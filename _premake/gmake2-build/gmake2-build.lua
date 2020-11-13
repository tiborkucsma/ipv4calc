premake.modules.lua = {}
local m = premake.modules.lua

local p = premake

newaction {
	trigger = "gmake2-build",
	description = "Build project using generated gmake2 files",

	execute = function()
		os.chdir("generated")
		os.execute("make")
	end,
}

return m