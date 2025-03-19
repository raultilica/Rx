cmake_minimum_required(VERSION 3.0.0)
project(Lab2_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2_4 main.c ui/ui.c
        service/service.h
        service/service.c
        domain/domain.c
        domain/domain.h
        teste/teste.h
        teste/teste.c
        repo/repo.c
        repo/repo.h
        repo/lista.h
        validator/validator.h
        validator/validator.c
        repo/lista.c)
