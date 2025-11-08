add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp core/app.cpp core/app.h)

target_link_libraries(${PROJECT_NAME} PRIVATE external)