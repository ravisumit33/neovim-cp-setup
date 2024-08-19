return {
	{
		"xeluxee/competitest.nvim",
		dependencies = "MunifTanjim/nui.nvim",
		config = function()
			require("competitest").setup({
				compile_command = {
					cpp = { exec = "g++", args = { "-Wall", "-g", "-std=c++20", "$(FNAME)", "-o", "$(FNOEXT)" } },
				},
				template_file = "template.$(FEXT)",
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
			local dap = require("dap")
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
