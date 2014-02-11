task :default => :generate_stabs

desc "generate stabs"
task :generate_stabs do
  output_dir = "generated"
  Dir.mkdir(output_dir) unless Dir.exists?(output_dir)
  Dir["pkgs/*.pkg"].each do |f|
    basename = File.basename(f, ".*")
    system "ruby lib/generate_stabs.rb #{f} cpp > #{output_dir}/#{basename}.cpp"
    system "ruby lib/generate_stabs.rb #{f} h   > #{output_dir}/#{basename}.h"
  end
end
