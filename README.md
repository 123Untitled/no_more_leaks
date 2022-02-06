# no_more_leaks 💦
### 42 school memory manager
#### mempush
- memory allocation  
- return 1 on success, 0 on fail
```c
char *str;
mempush(&str, sizeof(char), 64);
```
#### memfree
- memory desallocation
- return 1 on success, 0 on fail
```c
memfree(&str);
```
#### memreleased
- release all previous mempush()
- return number of released pointer
```c
memreleased();
```
![Alt Text](https://media3.giphy.com/media/y5sgdkj8S3mmB4JmO9/giphy.gif?cid=ecf05e472sqp2xnfrspl5p06z1ddldp9moeok18dpxah3cl3&rid=giphy.gif&ct=g)
