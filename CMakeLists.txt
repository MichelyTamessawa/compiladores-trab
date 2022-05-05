# Declaration et nommage du projet
project(parser)

# Minimum version of CMake to build this project
cmake_minimum_required(VERSION 2.6)

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(/usr/include/llvm-13)
include_directories(/usr/include/llvm-c-13)
# caso a versao 13 nao seja a default do sistema, e necessario incluir esses diretorios (includes)

# Packages
find_package(BISON)
find_package(FLEX)

# LLVM
# essa parte e necessaria para encontrar as implementacoes (acho, pelo que eu entendi)
link_libraries()
# O default do Ubuntu 20 e o llvm-10 (por isso tem que escrever llvm-config-13, pra ele pegar o 13)
# Do Ubuntu 21 o default e a v13, entao nao e necessario colocar o -13 (apenas llvm-config)
execute_process(COMMAND llvm-config-13 --libs OUTPUT_VARIABLE LIBS)
execute_process(COMMAND llvm-config-13 --system-libs OUTPUT_VARIABLE SYS_LIBS)
execute_process(COMMAND llvm-config-13 --ldflags OUTPUT_VARIABLE LDF)
#message(STATUS "Found LLVM: " ${LIBS})

string(STRIP ${LIBS} LIBS)
string(STRIP ${SYS_LIBS} SYS_LIBS)
string(STRIP ${LDF} LDF)

link_libraries(${LIBS} ${SYS_LIBS} ${LDF})

execute_process(COMMAND llvm-config-13 --cxxflags OUTPUT_VARIABLE CMAKE_CXX_FLAGS)
string(STRIP ${CMAKE_CXX_FLAGS} CMAKE_CXX_FLAGS)

# Variables
set(CXX "clang++")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -W -Werror -pedantic -g")
set(CMAKE_CXX_FLAGS "-O3 -DLLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING -Wall -W -pedantic -Wno-error=unused-parameter -Wno-unused-parameter")
# a compilacao do llvm estava dando muitos warnings de parametros nao utilizados.
# as flags -Wno-error=unused-parameter -Wno-unused-parameter foram adicionadas para suprimir esses warnings
# mas cuidado que isso afeta a nossa implementacao tambem.
# nao encontrei um jeito de usar as flags em uma parte e em outra nao

# Files
file(GLOB HH_FILES *.hh)
file(GLOB SRC_FILES *.cc)

# BISON and FLEX
bison_target(Parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cc) 
flex_target(Scanner scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)
add_flex_bison_dependency(Scanner Parser)

# Output directoru
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Add the binary and sources
add_executable(
    sc
    ${HH_FILES}
    ${SRC_FILES}
    ${FLEX_Scanner_OUTPUTS}
    ${BISON_Parser_OUTPUTS}
    )