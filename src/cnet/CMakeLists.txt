add_library (cnet 
"include/cnet.h" "include/types.h" "include/instance.h" "include/server.h" "include/socket.h"
"src/socket.cpp" "src/server.cpp" "src/client.cpp" "include/client.h" "include/bytes.h" "src/bytes.cpp")


if(WIN32)
target_link_libraries(cnet PRIVATE Ws2_32.lib)
target_sources(cnet PRIVATE
  "src/windows/instance.cpp")
elseif(UNIX)
target_sources(cnet PRIVATE
  "src/linux/instance.cpp")
endif()