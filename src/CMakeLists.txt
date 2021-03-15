file(GLOB DISPATCHER_SOURCE dispatcher/*.cpp)
file(GLOB DISPATCHER_HEADER dispatcher/*.h)

file(GLOB SLICE_SOURCE cpp/*.cpp)
file(GLOB SLICE_HEADER headers/*.h)

add_executable(srcslice ${DISPATCHER_SOURCE} ${DISPATCHER_HEADER} ${SLICE_SOURCE} ${SLICE_HEADER})
target_link_libraries(srcslice srcsaxeventdispatch srcsax_static ${LIBXML2_LIBRARIES})