//
// Created by Divium on 11.12.2023.
//
#pragma once

namespace mit {
    template<class T> concept CComparable = requires(T object, T object2) {
//        object > object2;
//        object >= object2;
//        object < object2;
//        object <= object2;
//        object == object2;
//        object != object2;
        object <=> object2;
    };
}