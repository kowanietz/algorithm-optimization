import ctypes
import os
import sys

if sys.platform == "darwin":
    LIB_NAME = "libsorting.dylib"
elif sys.platform == "win32":
    LIB_NAME = "sorting.dll"
else:
    LIB_NAME = "libsorting.so"

_LIB_PATH = os.path.join(os.path.dirname(__file__), "..", "build", "sorting", LIB_NAME)

lib = ctypes.CDLL(_LIB_PATH)

lib.bubble_sort_naive.restype = None
lib.bubble_sort_naive.argtypes = [
    ctypes.POINTER(ctypes.c_int32),
    ctypes.c_uint32,
]

lib.bubble_sort_optimized.restype = None
lib.bubble_sort_optimized.argtypes = [
    ctypes.POINTER(ctypes.c_int32),
    ctypes.c_uint32,
]

lib.insertion_sort.restype = None
lib.insertion_sort.argtypes = [
    ctypes.POINTER(ctypes.c_int32),
    ctypes.c_uint32,
]

lib.selection_sort.restype = None
lib.selection_sort.argtypes = [
    ctypes.POINTER(ctypes.c_int32),
    ctypes.c_uint32,
]


def bubble_sort_naive(arr: list[int]) -> list[int]:
    n = len(arr)
    arr_copy = arr.copy()
    c_arr = (ctypes.c_int32 * n)(*arr_copy)
    lib.bubble_sort_naive(c_arr, n)
    return list(c_arr)


def bubble_sort_optimized(arr: list[int]) -> list[int]:
    n = len(arr)
    arr_copy = arr.copy()
    c_arr = (ctypes.c_int32 * n)(*arr_copy)
    lib.bubble_sort_optimized(c_arr, n)
    return list(c_arr)


def insertion_sort(arr: list[int]) -> list[int]:
    n = len(arr)
    arr_copy = arr.copy()
    c_arr = (ctypes.c_int32 * n)(*arr_copy)
    lib.insertion_sort(c_arr, n)
    return list(c_arr)


def selection_sort(arr: list[int]) -> list[int]:
    n = len(arr)
    arr_copy = arr.copy()
    c_arr = (ctypes.c_int32 * n)(*arr_copy)
    lib.selection_sort(c_arr, n)
    return list(c_arr)
