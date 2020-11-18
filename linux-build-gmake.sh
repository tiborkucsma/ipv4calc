#!/bin/sh
./_premake/bin/premake5 gmake2
pushd generated
make
popd