add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp core/app.cpp core/app.h level/level_generator.cpp level/level_generator.h camera/camera.cpp camera/camera.h components/game_object.cpp components/game_object.h components/transform.cpp components/transform.h)

target_link_libraries(${PROJECT_NAME} PRIVATE external)