project('murmur3', 'c', version: '0.1')

inc_murmur3 = include_directories('.')
lib_murmur3 = shared_library('murmur3', 'murmur3.c')

exe_example = executable('example', 'example.c', include_directories: inc_murmur3, link_with: lib_murmur3)

exe_test1 = executable('test1', 'test.c', link_with: lib_murmur3)
test('Unit test', exe_test1, is_parallel: false)



