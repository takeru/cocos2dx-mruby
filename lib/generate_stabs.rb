#!ruby
# Generates mruby bindings from pkg definition.

STATIC = 1 << 0
ATTR_ACCESSOR = 1 << 1
CONSTRUCTOR = 1 << 2
CUSTOM = 1 << 3

def is_static?(flag)
  return flag & STATIC != 0
end

def is_attr_accessor?(flag)
  return flag & ATTR_ACCESSOR != 0
end

def is_constructor?(flag)
  return flag & CONSTRUCTOR != 0
end

def is_custom?(flag)
  return flag & CUSTOM != 0
end

def get_plain_type(type)
  type.gsub(/(&|\*|const)/, '').strip
end

def is_pointer_type(type)
  type.index('*')
end

class String
  def capitalize1
    self[0].upcase + self[1..-1]
  end
end


class MrubyStubGenerator
  def put_header(module_name)
    print <<EOD
#{Header}
#include "mruby/mruby.h"
#include "mruby/mruby/class.h"
#include "mruby/mruby/data.h"
#include "mruby/mruby/string.h"
#include "mruby/mruby/variable.h"
#include <new>
#include <assert.h>

static void dummy(mrb_state *mrb, void *ptr) {
  //printf("dummy called\\n");
}

// TODO: Use different data type for each class.
static struct mrb_data_type dummy_type = { "Dummy", dummy };

static bool get_bool(mrb_value x) {
  return mrb_bool(x);
}

static int get_int(mrb_value x) {
  if (mrb_fixnum_p(x)) {
    return mrb_fixnum(x);
  } else if (mrb_float_p(x)) {
    return mrb_float(x);
  } else {
    return 0;
  }
}

static float get_float(mrb_value x) {
  if (mrb_fixnum_p(x)) {
    return mrb_fixnum(x);
  } else if (mrb_float_p(x)) {
    return mrb_float(x);
  } else {
    return 0;
  }
}

static struct RClass* getClass(mrb_state *mrb, const char* className) {
#{
  if module_name
    ["  RClass* mod = mrb_module_get(mrb, \"#{module_name}\");",
     "  return mrb_class_get_under(mrb, mod, className);"].join("\n")
  else
    '  return mrb_class_get(mrb, className);'
  end
}
}

template <class T>
mrb_value wrap(mrb_state *mrb, T* ptr, const char* type) {
  struct RClass* tc = getClass(mrb, type);
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &dummy_type, NULL));
  DATA_TYPE(instance) = &dummy_type;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}
EOD
  end

  def convert_constructors(klass, methods)
    methods.map do |method|
      if is_constructor?(method[0])
        flag, params = method
        [flag | STATIC, "#{klass}*", "__ctor", params]
      else
        method
      end
    end
  end

  def generate_h(filename)
    basename = File.basename(filename, '.*')
    puts <<END
#ifndef __#{basename.upcase}_H_
#define __#{basename.upcase}_H_

#include "mruby/mruby.h"

void install#{basename}(mrb_state *mrb);

#endif // __#{basename.upcase}_H_
END
  end

  def generate_cpp(filename, module_name, constants, classes, functions)
    put_header(module_name)

    classes.each do |klass, info|
      methods = convert_constructors(klass, info[:methods])
      klass_methods = group_class_methods_by_name(methods)

      print <<EOD

////////////////////////////////////////////////////////////////
// #{klass}
EOD
      klass_methods.each do |method_name, methods|
        declare_methods(klass, method_name, methods)
      end

      parent = info.has_key?(:parent) ? info[:parent] : nil
      declare_class(klass, parent, klass_methods)
    end

      print <<EOD

////////////////////////////////////////////////////////////////
// Functions.
EOD

    functions.each do |return_type, func_name, params|
      declare_function(return_type, func_name, params)
    end

    puts ""
    puts "void install#{File.basename(filename, '.*')}(mrb_state *mrb) {"

    if module_name
      puts "  struct RClass* mod = mrb_define_module(mrb, \"#{module_name}\");"
    else
      puts "  struct RClass *mod = mrb->kernel_module;"
    end

    register_constants(constants)

    # TODO: Define functions under module.
    functions.each do |return_type, func_name, params|
      ruby_func_name = func_name
      if ruby_func_name[0] =~ /[A-Z]{1}/
        ruby_func_name = "_" + ruby_func_name
      end
      puts %!  mrb_define_module_function(mrb, mod, "#{ruby_func_name}", #{func_name}__, MRB_ARGS_ANY());!
    end

    classes.each do |klass, _|
      puts "  install#{klass}(mrb, mod);"
    end

    puts "}"
  end

  def register_constants(constants)
    constants.each do |constant|
      register_constant(constant[0], constant[1])
    end
  end

  def register_constant(type, varname)
    puts <<EOD
  mrb_define_const(mrb, mod, "#{varname.capitalize1}", #{c_value_to_mruby_value(type, varname)});
EOD
  end

  def declare_function(return_type, func_name, params)
    declare_methods(nil, func_name, [[0, return_type, params]])
  end

  def declare_methods(klass, method_name, methods)
    flag = methods[0][0]
    if is_attr_accessor?(flag)
      declare_attr_accessor(klass, method_name, methods[0][1])  # Assumes attr_accessor does not have override methods.
      return
    end

    get_args = true
    #if methods.size == 1
    #  get_arg_count = ''
    #  if methods[0][2].empty?
    #    get_args = false
    #  end
    #end

    block_required = false
    methods.each do |_, _, params|
      block_required |= params.include?('block')
    end

    c_func_name = klass ? "#{klass}_#{method_name}" : "#{method_name}__"

    puts ""
    puts "static mrb_value #{c_func_name}(mrb_state *mrb, mrb_value self) {"
    if get_args
      if block_required
        print <<EOD
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
EOD
      else
        print <<EOD
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
EOD
      end
    end

    if false && methods.size == 1
      flag, return_type, params, opts = methods[0]
      declare_exec_method(klass, method_name, flag, return_type, params, opts, 0);
    else
      methods.each_with_index do |method, i|
        flag, return_type, params, opts = method
        block_required = params.include?('block')
        arg_count = params.size - (block_required ? 1 : 0)
        has_else = i == 0 ? '' : '} else '
        puts "  #{has_else}if (arg_count == #{arg_count}) {"
        declare_exec_method(klass, method_name, flag, return_type, params, opts, 1);
      end
      print <<EOD
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "#{klass}\##{method_name}");
    return mrb_nil_value();
  }
EOD
    end

    puts "}"
  end

  def declare_exec_method(klass, method_name, flag, return_type, params, opts, indent)
    if is_custom?(flag)
      puts opts[:code];
      return
    end

    converted_params = []  # 0=type, 1=name, 2=value
    index = 0
    params.each do |type|
      a = if type == 'block'
            ['int', 'blockHandler', 'registerProc(mrb, self, block)']
          else
            i = index
            index += 1
            converter = mruby_value_to_c_value(type, "args[#{i}]")
            [type, "p#{i}", converter]
          end
      converted_params.push(a)
    end

    convert_params = converted_params.map {|type, name, val| "#{type} #{name} = #{val};"}
    cparams = converted_params.map {|_, name, _| name}.join(', ')

    if return_type != 'void'
      return_var = "#{return_type} retval = "
      return_stmt = "return #{c_value_to_mruby_value(return_type, 'retval')};"
    else
      return_var = ''
      return_stmt = 'return mrb_nil_value();'
    end

    if !klass
      get_instance = ''
      call_method = "#{method_name}"
    elsif is_constructor?(flag)
      get_instance = ''
      call_method = "new #{klass}"
      return_stmt = "DATA_PTR(self) = retval; return self;"
    elsif is_static?(flag)
      get_instance = ''
      call_method = "#{klass}::#{method_name}"
    else
      get_instance = "#{klass}* instance = static_cast<#{klass}*>(DATA_PTR(self));"
      call_method = "instance->#{method_name}"
    end

    str = <<EOD
#{convert_params.map {|s| "  #{s}"}.join("\n")}
  #{get_instance}
  #{return_var}#{call_method}(#{cparams});
  #{return_stmt}
EOD
    if indent == 0
      print str
      return
    end
    str.split("\n").each do |line|
      puts ("  " * indent) + line
    end
  end

  def declare_attr_accessor(klass, member_name, return_type)
    print <<EOD

static mrb_value #{klass}_#{member_name}(mrb_state *mrb, mrb_value self) {
  #{klass}* instance = static_cast<#{klass}*>(DATA_PTR(self));
  return #{c_value_to_mruby_value(return_type, "instance->#{member_name}")};
}

static mrb_value #{klass}_set_#{member_name}(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  #{klass}* instance = static_cast<#{klass}*>(DATA_PTR(self));
  instance->#{member_name} = #{mruby_value_to_c_value(return_type, "o")};
  return mrb_nil_value();
}
EOD
  end

  def declare_class(klass, parent, methods)
    if parent
      get_parent = "getClass(mrb, \"#{parent}\")";
    else
      get_parent = 'mrb->object_class';
    end
    print <<EOD

static void install#{klass}(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = #{get_parent};
  struct RClass* tc = mrb_define_class_under(mrb, mod, "#{klass.capitalize1}", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
EOD
    methods.each do |method_name, methods|
      if is_constructor?(methods[0][0])
        puts %!  mrb_define_method(mrb, tc, "initialize", #{klass}_#{method_name}, MRB_ARGS_ANY());!
      elsif is_static?(methods[0][0]) && !is_constructor?(methods[0][0])
        puts %!  mrb_define_class_method(mrb, tc, "#{method_name}", #{klass}_#{method_name}, MRB_ARGS_ANY());!
      elsif is_attr_accessor?(methods[0][0])
        puts %!  mrb_define_method(mrb, tc, "#{method_name}", #{klass}_#{method_name}, MRB_ARGS_NONE());!
        puts %!  mrb_define_method(mrb, tc, "#{method_name}=", #{klass}_set_#{method_name}, MRB_ARGS_REQ(1));!
      else
        puts %!  mrb_define_method(mrb, tc, "#{method_name}", #{klass}_#{method_name}, MRB_ARGS_ANY());!
      end
    end
    puts "}"
  end

  def group_class_methods_by_name(methods)
    klass_methods = Hash.new{|h, k| h[k] = []}
    methods.each do |info|
      method_name = info[2]
      info = info.dup
      info.delete_at(2)
      klass_methods[method_name].push(info)
    end
    return klass_methods
  end

  def mruby_value_to_c_value(type, varname)
    case type
    when 'bool'
      return "get_bool(#{varname})"
    when 'int', 'unsigned int', 'short', 'unsinged short', 'long', 'unsigned long', 'char', 'unsigned char'
      return "get_int(#{varname})"
    when 'float'
      return "get_float(#{varname})"
    when 'double'
      return "get_double(#{varname})"
    when 'const char*'
      return "mrb_string_value_ptr(mrb, #{varname})"
    when 'const std::string&'
      return "std::string(mrb_string_value_ptr(mrb, #{varname}))"
    when 'block'
      return "get_bool(#{varname})"
    else
      if is_enum?(type)
        return "(#{type})mrb_fixnum(#{varname})"
      end

      plain_type = get_plain_type(type)
      if is_pointer_type(type)
        return "static_cast<#{plain_type}*>(DATA_PTR(#{varname}))"
      else
        return "*static_cast<#{plain_type}*>(DATA_PTR(#{varname}))"
      end
    end
  end

  def c_value_to_mruby_value(type, varname)
    case type
    when 'bool'
      return "mrb_bool_value(#{varname})"
    when 'int', 'unsigned int', 'short', 'unsinged short', 'long', 'unsigned long', 'char', 'unsigned char'
      return "mrb_fixnum_value(#{varname})"
    when 'float'
      return "mrb_float_value(mrb, #{varname})"
    when 'double'
      return "mrb_double_value(mrb, #{varname})"
    when 'std::string'
      return "mrb_str_new(mrb, #{varname}.c_str(), #{varname}.size())"
    else
      plain_type = get_plain_type(type)
      if is_pointer_type(type)
        if type =~ /^void\s*\*+/  # Treat as voidp
          return %!(#{varname} == NULL ? mrb_nil_value() : mrb_voidp_value(mrb, #{varname}))!
        else
          return %!(#{varname} == NULL ? mrb_nil_value() : wrap(mrb, #{varname}, "#{plain_type.capitalize1}"))!
        end
      else
        # TODO: Think other way to copy object.
        return %!wrap(mrb, new(mrb_malloc(mrb, sizeof(#{plain_type}))) #{plain_type}(#{varname}), "#{plain_type.capitalize1}")!
      end
    end
  end

  def is_enum?(type)
    Object.constants.index(:Enums) && Enums.index(type)
  end
end


if $0 == __FILE__
  raise "usage: ruby generate_stab.rb PKG_FILE cpp|h" if ARGV.size!=2
  filename = ARGV.shift
  filetype = ARGV.shift
  content = open(filename).read
  eval(content)

  gen = MrubyStubGenerator.new
  module_name = Object.constants.index(:ModuleName) ? ModuleName : nil
  constants = Object.constants.index(:Constants) ? Constants : []
  classes = Object.constants.index(:Classes) ? Classes : {}
  functions = Object.constants.index(:Functions) ? Functions : []

  case filetype
  when "cpp"
    gen.generate_cpp(filename, module_name, constants, classes, functions)
  when "h"
    gen.generate_h(filename)
  else
    raise ""
  end
end
