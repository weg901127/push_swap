"----------------------------------------------------------------------------plugin
call plug#begin('~/.config/nvim/plugged')
" Use release branch
Plug 'neoclide/coc.nvim', {'branch': 'release'}
" Or latest tag
Plug 'neoclide/coc.nvim', {'tag': '*', 'branch': 'release'}
" Or build from source code by use yarn: https://yarnpkg.com
Plug 'neoclide/coc.nvim', {'do': 'yarn install --frozen-lockfile'}

Plug 'nanotech/jellybeans.vim'

Plug 'preservim/nerdtree'

Plug 'mattn/emmet-vim'

Plug 'puremourning/vimspector'

Plug 'jeetsukumaran/vim-buffergator'

Plug 'majutsushi/tagbar'

Plug 'lukas-reineke/indent-blankline.nvim'

Plug 'airblade/vim-gitgutter'

Plug 'tpope/vim-fugitive'

Plug 'bfrg/vim-cpp-modern'

call plug#end()
let g:coc_data_home=stdpath('data')."/coc-extensions"
let g:indent_blankline_space_char = '.'
let g:indent_blankline_char = '.'

let g:cpp_member_highlight = 1
let g:c_ansi_typedefs = 1
match Type /\tt_\w*/
"----------------------------------------------------------------------------plugin
"------------------------------------------------------------------------vimspector
let g:vimspector_enable_mappings = 'HUMAN'
nmap <leader>dd :call vimspector#Launch()<CR>
nmap <leader>dx :VimspectorReset<CR>
nmap <Leader>di <Plug>VimspectorBalloonEval
nmap <leader>de :VimspectorEval
nmap <leader>dw :VimspectorWatch
nmap <leader>do :VimspectorShowOutput
nmap <leader>dc :!cc -g -I./libft/libft.h -L./libft/ -lft *.c -o main;./main<CR>
let g:vimspector_install_gadgets = [ 'debugpy', 'vscode-go', 'CodeLLDB' ]
"------------------------------------------------------------------------vimspector
"------------------------------------------------------------------------nerdtree
nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
"nnoremap <C-t> :NERDTreeToggle<CR>
"------------------------------------------------------------------------nerdtree
"------------------------------------------------------------------------mouse
set mouse=a
map <ScrollWheelUp> <C-u>
map <ScrollWheelDown> <C-d>
set scroll=2
"------------------------------------------------------------------------mouse
" Custom vim-airline integration
"function! StatusDiagnostic() abort
"    let info = get(b:, 'coc_diagnostic_info', {})
"    if empty(info) | return '' | endif
"    let msgs = []
"    if get(info, 'error', 0)
"        call add(msgs, 'E' . info['error'])
"    endif
"    if get(info, 'warning', 0)
"        call add(msgs, 'W' . info['warning'])
"    endif
"    return join(msgs, ' '). ' ' . get(g:, 'coc_status', '') . ' ' . get(b:, 'coc_current_function', '')
"endfunction
"let g:airline_section_c = '%{StatusDiagnostic()}'

"----------------------------------------------------------------------------------
"-- config
"----------------------------------------------------------------------------------
" set UTF-8 encoding
let g:gruvbox_contrast_dark="hard"
set background=dark
autocmd vimenter * colorscheme jellybeans

set enc=utf-8
set fenc=utf-8
set termencoding=utf-8

set hlsearch
set ignorecase

set nocompatible        " disable vi compatibility (emulation of old bugs)
set autoindent  " use indentation of previous line
set smartindent " use intelligent indentation for C

" configure tabwidth and insert spaces instead of tabs
set ts=4 sw=4 et     " indent also with 4 spaces
set noexpandtab        " expand tabs to spaces
" wrap lines at 120 chars. 80 is somewaht antiquated with nowadays displays.
set textwidth=120
" turn syntax highlighting on
set t_Co=256
syntax on
" colorscheme wombat256
set number      " turn line numbers on
set showmatch   " highlight matching braces

set comments=sl:/*,mb:\ *,elx:\ */      " intelligent comments


"----------------------------------------------------------------------------------
"-- keyboard mappings
"----------------------------------------------------------------------------------

map <F2> :w<CR>
map <F3> :!cc %;./a.out<CR>
map <leader><F1> :TagbarToggle<CR>
" switch between header/source with F4
"map <F4> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>
" goto definition with F12
"map <F12> <C-]>

if has('nvim')
    :tnoremap <A-h> <C-\><C-n><C-w>h
    :tnoremap <A-j> <C-\><C-n><C-w>j
    :tnoremap <A-k> <C-\><C-n><C-w>k
    :tnoremap <A-l> <C-\><C-n><C-w>l
endif
:nnoremap <A-h> <C-w>h
:nnoremap <A-j> <C-w>j
:nnoremap <A-k> <C-w>k
:nnoremap <A-l> <C-w>l

