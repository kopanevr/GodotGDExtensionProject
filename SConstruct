from SCons.Script import SConscript, Glob, Default

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["inc/"])
sources = Glob("src/*.cpp")

library = env.SharedLibrary("demo/bin/lib{}{}".format(env["suffix"], env["SHLIBSUFFIX"]), source=sources)

Default(library)
