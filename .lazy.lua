local dap = require("dap")

-- Define a custom function to compile and debug cpp file
local function compile_and_debug()
	local filedir = vim.fn.expand("%:p:h")
	local filename = vim.fn.expand("%:t:r")
	local filepath = vim.fn.expand("%:p")
	local outname = filedir .. "/" .. filename

	-- Compile the current C++ file with debug symbols
	local compile_cmd = 'g++ -Wall -Wextra -g -std=c++20 "' .. filepath .. '" -o "' .. outname .. '"'

	print("Compiling: " .. outname)

	-- Execute the compilation command
	local result = vim.fn.system(compile_cmd)

	if vim.v.shell_error ~= 0 then
		print("Compilation failed:\n" .. result)
		return
	end

	-- Define the debug configuration
	local debug_config = {
		name = "Debug " .. filename,
		type = "codelldb",
		request = "launch",
		program = outname,
		cwd = filedir,
		stopOnEntry = false,
		setupCommands = {
			{
				text = "-enable-pretty-printing",
				description = "Enable pretty printing",
				ignoreFailures = false,
			},
		},
	}

	-- Run the debug configuration
	dap.run(debug_config)
end

-- Create a command that runs the function
vim.api.nvim_create_user_command("BuildAndDebug", compile_and_debug, {})
-- Define the key mapping for BuildAndDebug
vim.api.nvim_set_keymap("n", "<leader>cpd", ":BuildAndDebug<CR>", { noremap = true, silent = true })
-- Define the key mapping for running sample test cases
vim.api.nvim_set_keymap("n", "<leader>cpt", ":CompetiTest run<CR>", { noremap = true, silent = true })
-- Define the key mapping for receiving contest
vim.api.nvim_set_keymap("n", "<leader>cpr", ":CompetiTest receive contest<CR>", { noremap = true, silent = true })

return {
	{
		"xeluxee/competitest.nvim",
		dependencies = "MunifTanjim/nui.nvim",
		config = function()
			require("competitest").setup({
				compile_command = {
					cpp = {
						exec = "g++",
						args = { "-Wall", "-Wextra", "-g", "-std=c++20", "$(FNAME)", "-o", "$(FNOEXT)" },
					},
				},
				template_file = "template.$(FEXT)",
				evaluate_template_modifiers = true,
				received_contests_directory = "$(CWD)/$(JUDGE)",
				received_contests_prompt_directory = false,
				received_contests_prompt_extension = false,
				open_received_contests = false,
				received_problems_path = "$(CWD)/$(JUDGE)/$(PROBLEM).$(FEXT)",
				received_problems_prompt_path = false,
				view_output_diff = true,
			})
		end,
	},
	{
		"nvim-neo-tree/neo-tree.nvim",
		opts = {
			window = {
				mappings = {
					["<c-y>"] = {
						function(state)
							local node = state.tree:get_node()
							if node.type == "file" then
								-- Read the file content
								local content = vim.fn.readfile(node.path)
								-- Join the lines into a single string
								local file_content = table.concat(content, "\n")
								-- Copy the content to the system clipboard
								vim.fn.setreg("+", file_content)
								print("File content copied to clipboard!")
							else
								print("Not a file!")
							end
						end,
					},
				},
			},
		},
	},
	{
		"rcarriga/nvim-dap-ui",
		config = function(_, opts)
			local dapui = require("dapui")
			dapui.setup(opts)
			dap.listeners.after.event_initialized["dapui_config"] = function()
				dapui.open({})
			end
			dap.listeners.before.event_terminated["dapui_config"] = nil
			dap.listeners.before.event_exited["dapui_config"] = nil
		end,
	},
}
