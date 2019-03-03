#include "redisconn.hpp"
#include <iostream>
#include <stdlib.h>
#include "redispool.h"

int main(){
	//class redisconn * conn = new class redisconn("127.0.0.1",6379);
	//class redisconn * conn2 = new class redisconn("127.0.0.1",6379);
	//std::cout << conn->redisIP << std::endl;
	//conn->connect();
	class redisPool *connpool = new redisPool(5,10,"127.0.0.1",6379);
	std::shared_ptr<redisconn> conn = connpool->get_connection();
	//auth
	conn->sendCommand("AUTH yeelion");
	redisReply * m_reply = conn->getReply();
	if(m_reply->type == REDIS_REPLY_STATUS){
		std::cout << m_reply->str << std::endl;
	}
	conn->freeReply();
	conn->sendCommand("SET abc 123");
	redisReply * m_reply = conn->getReply();
	if(m_reply->type == REDIS_REPLY_STATUS){
		std::cout << m_reply->str << std::endl;
	}
	conn->freeReply();
	conn->sendCommand("AUTH music 45678");
	redisReply * m_reply = conn->getReply();
	if(m_reply->type == REDIS_REPLY_STATUS){
		std::cout << m_reply->str << std::endl;
	}
	conn->freeReply();
	return 0;
}
