# Specify version being used
cmake_minimum_required(VERSION 2.6)

#Project name
PROJECT(DMQ)
set(SNSRC ${DMQ_SOURCE_DIR}/src)
set(SNINC ${DMQ_SOURCE_DIR}/include)
include_directories(${SNINC})

set(INC
    ${SNINC}/user.hpp
    ${SNINC}/id.hpp
    ${SNINC}/distributor.hpp
    ${SNINC}/server.hpp
    )
set(SRC
    ${SNSRC}/user.cpp
    ${SNSRC}/id.cpp
    ${SNSRC}/main.cpp
    ${SNSRC}/distributor.cpp
    ${SNSRC}/server.cpp
    )

add_executable(dmq ${SRC} ${INC})
target_link_libraries(dmq)
