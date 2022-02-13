# no_more_leaks 💦
### 42 school memory manager
#### mempush
- memory allocation  
- return 1 on success, 0 on fail
- need address of pointer (&ptr), size of block, number of block
```c
char *str;
if (!mempush(&str, sizeof(char), 64))
    // error case code...
```
#### memfree
- memory desallocation
- return 1 on success, 0 on fail
- assign pointer to NULL in same time
```c
memfree(&str);
// str is now NULL
```
#### memreleased
- release all previous mempush()
- return number of released pointer
- no need arguments
```c
memreleased();
// program is now clean to exit
```
![Alt Text](https://media3.giphy.com/media/y5sgdkj8S3mmB4JmO9/giphy.gif?cid=ecf05e472sqp2xnfrspl5p06z1ddldp9moeok18dpxah3cl3&rid=giphy.gif&ct=g)
