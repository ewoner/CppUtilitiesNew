{ pkgs }: {
	deps = [
		pkgs.clang_14
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}