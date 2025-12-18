{ pkgs }: {
	deps = [
   pkgs.systemd
   pkgs.nginx
   pkgs.fastfetch
		pkgs.clang
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}