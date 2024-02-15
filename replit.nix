{ pkgs }: {
	deps = [
   pkgs.vim
		pkgs.clang_14
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}