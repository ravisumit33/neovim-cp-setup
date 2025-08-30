local dap = require("dap")

-- Define a custom function to compile and debug cpp file
local function compile_and_debug()
	local filedir = vim.fn.expand("%:p:h")
	local filename = vim.fn.expand("%:t:r")
	local escaped_filename = filename:gsub("'", "'\\''")
	local filepath = vim.fn.expand("%:p")
	local escaped_filepath = filepath:gsub("'", "'\\''")

	local outname = filedir .. "/" .. filename
	local escaped_outname = filedir .. "/" .. escaped_filename

	-- Compile the current C++ file with debug symbols
	local compile_cmd = "g++ -Wall -Wextra -g -std=c++23 '" .. escaped_filepath .. "' -o '" .. escaped_outname .. "'"

	print("Compiling: " .. outname)
	print("Command: " .. compile_cmd)

	-- Execute the compilation command
	local result = vim.fn.system(compile_cmd)

	if vim.v.shell_error ~= 0 then
		print("Compilation failed:\n" .. result)
		return
	end

	-- Terminate any existing debugging session
	local current_session = dap.session()
	if current_session then
		print("Terminating existing debugging session...")
		dap.terminate()
		-- Wait for the session to terminate
		vim.wait(1000, function()
			return not dap.session()
		end)
		print("Existing session terminated.")
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
	print("Starting new debugging session...")
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
-- Define the key mapping for finding cpp files
vim.api.nvim_set_keymap(
	"n",
	"<leader>cpf",
	"<cmd>lua Snacks.picker.files({ pattern = 'file:cpp$ ' })<CR>",
	{ noremap = true, silent = true }
)

return {
	{
		"xeluxee/competitest.nvim",
		dependencies = "MunifTanjim/nui.nvim",
		config = function()
			require("competitest").setup({
				compile_command = {
					cpp = {
						exec = "g++",
						args = { "-Wall", "-Wextra", "-g", "-std=c++23", "$(FNAME)", "-o", "$(FNOEXT)" },
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
