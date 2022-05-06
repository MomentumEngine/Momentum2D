cmake_minimum_required(VERSION 3.12)
project(glad)

add_library(glad    include/vk_platform.h
                    include/KHR/khrplatform.h
                    include/glad/glad.h
                    include/glad/vulkan.h
                    src/glad.c
                    src/vulkan.c)


target_include_directories(glad PUBLIC include/)