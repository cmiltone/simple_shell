"/* ===========================================================================
" My .vimrc file
"==============================================================================

" Sets numbers to the beginning of every line.
" Display the current line and column in Vim
set nu

" Change the default color scheme
colorscheme slate

" Maps the buffer for files such that you can easily navigate between files
" that are currently opened
map <F2> :bprev<CR>
map <F3> :bnext<CR>

" A quick way to auto source my .vimrc file with ease
map <F5> :source ~/.vimrc<CR>

" Auto indents my .vimrc file
set autoindent

" Intelligent indentation for C code
set cindent

" Enable syntax highlighting in Vim
syntax enable

" Auto fixes trailing whitespaces once you save your file
autocmd BufWritePre * %s/\s\+$//e

" Auto formatting of comments flag
" Note that the set formatoptions=tcqro line sets the formatoptions option
" to its default value, which includes the t flag for automatic formatting of
" text, the c flag for automatic formatting of comments, and the q flag for
" automatic formatting of comments when you type q.
set formatoptions=tcqro
autocmd FileType c,cpp,java setlocal formatoptions+=ro


"/* ===========================================================================
"	End of my .vimrc file
" =============================================================================
