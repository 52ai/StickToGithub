#include <iostream>
#include <string>
#include <hiredis/hiredis.h>

int main(int argc, const char **argv){

    struct timeval timeout = {2, 0}; //2s的超时时间
    //redisContext 是Redis操作对象
    redisContext *pRedisContext = (redisContext*)redisConnectWithTimeout("127.0.0.1",6379,timeout);
    if((NULL == pRedisContext) || (pRedisContext->err)){
        if(pRedisContext){
            std::cout << "connect error:"<< pRedisContext->errstr << std::endl;
        }
        else{
            std::cout << "connect error:can't allocate redis context." << std::endl;
        }
        return -1;
    }

    /*PING SERVER*/
    //residReply 是Redis命令回复对象，redis返回的信息保存在redisReply对象中
    redisReply *pRedisReply = (redisReply*)redisCommand(pRedisContext, "ping");//执行INFO命令
    std::cout << pRedisReply->str << std::endl;
    //当多条Redis命令使用同一个redisReply对象时
    //每一次执行完Redis命令后需要清空redisReply以免对下一次的Redis操作造成影响
    freeReplyObject(pRedisReply);//释放redisReply空间

    /*Set a Key*/
    pRedisReply = (redisReply*)redisCommand(pRedisContext, "set city beijing");
    std::cout << pRedisReply->str << std::endl;
    freeReplyObject(pRedisReply);

    /*Try a Get*/
    pRedisReply = (redisReply*)redisCommand(pRedisContext, "get city");//执行INFO命令
    std::cout << pRedisReply->str << std::endl;
    freeReplyObject(pRedisReply);//释放redisReply空间

    /*Get multi elements */
    pRedisReply = (redisReply*)redisCommand(pRedisContext,"hgetall %s", "user");
    if(pRedisReply->type == REDIS_REPLY_ARRAY){
        for(size_t s_i=0;s_i<pRedisReply->elements;s_i++){
            std::cout << pRedisReply->element[s_i]->str << " ";
        }
        std::cout << std::endl;
    }

    redisFree(pRedisContext);//断开链接并释放redisContext空间
    return 0;

}
