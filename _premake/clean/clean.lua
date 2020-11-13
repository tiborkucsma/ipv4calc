premake.modules.lua = {}
local m = premake.modules.lua

local p = premake

newaction {
	trigger = "clean",
	description = "Clean build files",

	execute = function()
		os.rmdir("build/**")
	end,
}

return m