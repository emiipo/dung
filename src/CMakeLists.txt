add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp core/app.cpp core/app.h level/level_generator.cpp level/level_generator.h rendering/camera.cpp rendering/camera.h components/component.cpp components/component.h components/game_object.cpp components/game_object.h components/world_object.cpp components/world_object.h components/transform.cpp components/transform.h util/common.h)

target_link_libraries(${PROJECT_NAME} PRIVATE external)