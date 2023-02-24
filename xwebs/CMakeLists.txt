cmake_minimum_required(VERSION 3.16)
project(xwebs CXX)
set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(xwebs
		xwebs.cpp
        base/CountDownLatch.cpp
        base/Thread.cpp
        base/ThreadPool.cpp
        base/buffer.cpp
        http/httpresponse.cpp
        http/httprequest.cpp
        http/httpconn.cpp
        http/webserver.cpp
		heaptimer.cpp
		epoller.cpp
        )
target_link_libraries(xwebs pthread)
