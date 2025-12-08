add_library(engine OBJECT
    main.cpp 
    core/app.cpp 
    core/app.h 
    core/SDL_event_manager.cpp 
    core/SDL_event_manager.h 
    events/event.cpp 
    events/event.h 
    rendering/render_manager.cpp 
    rendering/render_manager.h 
    rendering/renderer.cpp 
    rendering/renderer.h 
    rendering/camera.cpp 
    rendering/camera.h 
    components/component.cpp 
    components/component.h 
    components/game_object.cpp 
    components/game_object.h 
    components/world_object.cpp 
    components/world_object.h 
    components/transform.cpp 
    components/transform.h 
    util/common.h 
    components/collider.cpp 
    components/collider.h 
    input/input_manager.cpp 
    input/input_manager.h)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(engine PUBLIC external)