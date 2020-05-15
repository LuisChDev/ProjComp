let
  pkgs = import <nixpkgs> {};
in
pkgs.mkShell {
  nativeBuildInputs = [
    pkgs.cmake
  ];
  buildInputs = [
    pkgs.ccls
    pkgs.gcc
    pkgs.gdb
  ];
}
