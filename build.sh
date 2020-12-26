
root=$(pwd)

### CMAKE
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

function MAKE {
  make -j$(($(nproc) + 2))
}

function make_boost {
cd ${root}/dependencies/boost
  git submodule update \
    --depth 1 \
    --init \
    --recursive
  ./bootstrap.sh \
    --with-toolset=clang \
    --without-libraries=python
  ./b2 clean
  ./b2 \
    --prefix=${root}/artifacts \
    toolset=clang \
    variant=release \
    threading=multi
cd ${root}
}

function make_glfw {
cd ${root}/dependencies/glfw
  git checkout 3.3.2
  git clean -dfx
cd ${root}
mkdir -p ${root}/.cmake/glfw
cd ${root}/.cmake/glfw
  cmake \
   -DCMAKE_INSTALL_PREFIX=${root}/artifacts \
   -DCMAKE_USER_MAKE_RULES_OVERRIDE=${root}/ClangOverrides.txt \
    ${root}/dependencies/glfw
  MAKE
cd ${root}
}

function make_bulldog {
mkdir -p ${root}/.cmake/bulldog
  cmake \
    -DCMAKE_INSTALL_PREFIX=${root}/artifacts \
    ${root}
  MAKE
cd ${root}
}

#make_boost
#make_glfw
make_bulldog
