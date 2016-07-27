/******************************************************************

  Chapter 1. 윈속에 대한 소개 

	1) 소켓 생성 
	2) 소켓 닫기
******************************************************************/

/*
   소켓을 이용하여 통신을 하위 위한 기본 요건은 통신 양단이 동일한 
   프로토콜을 사용하는 것이다.(TCP or UDP) 

   socket() 함수는 사용자가 요청한 프로토콜을 이용하여 통신을 할 수 
   있도록 
   내부적으로 리소스를 할당하고, 이를 접근할 수 있는 일종의 
   핸들값(SOCKET타입, 32bit 정수)을 리턴한다. 
*/


//---------------------------------------------------------------- 
//   1) 소켓 생성
//---------------------------------------------------------------- 
/*
	SOCKET	socket(
		int		af,
		int		type,
		int		protocol
	);

    1인자 : 프로토콜의 어드레스 패밀리(address family)
	        -> 프로토콜별 주소 체계 형태 : IPv4 : AF_INET

	  * 주소 체계
      통신을 하기 위해서는 통신 상대를 유일하게 지정할 수 있는 
	  주소가 필요 
	  주소 체계(address family)란 이러한 주소 지정 방법을 지칭하는
	  용어임. 
	  주소 체계는 네트워크 프로토콜의 종류에 따라 달라지므로, 
	  주소 체계를 지정하는 것이 자신이 사용할 프로토콜을 선택하기 
	  위한 첫번째 관문이 된다. 

      winsock2.h 파일안에 AF_ 로 시작하는 상수값이 여기에 해당된다. 
	  #define AF_INET	2  // internetwork : UDP, TCP


    2인자 : 프로토콜의 소켓 타입 
	        -> TCP/IP 기반 소켓 생성 : SOCK_STREAM
			-> UDP/IP 기반 소켓 생성 : SOCK_DGRAM

     * 소켓 타입
     사용할 프로토콜의 특성을 나타내는 값 
	 SOCK_STREAM	: 신뢰성있는 데이터 전송 기능 제공, 
					  연결형 프로토콜
	 SOCK_DGRAM		: 비신뢰적인 데이터 전송 기능 제공, 
					  비연결형 프로토콜

    3인자 : 동일한 어드레스 패밀리에 대하여 여러 개의 프로토콜이
	        존재할 경우 사용
			-> TCP  : IPPROTO_TCP
			-> UDP  : IPPROTO_UDP


   * 프로토콜
     일반적으로 주소 체계와 소켓 타입이 같더라도 이에 대한 프로토콜이 
	 두 개이상 존재할 수 있다. 

     사용할 프로토콜	주소 체계	소켓 타입		프로토콜
	 TCP				AF_INET		SOCK_STREAM		IPPROTO_TCP
	 UDP				AF_INET		SOCK_DGRAM		IPPROTO_UDP

     => 프로토콜 사용시 모호함이 없을 경우 마지막 프로토콜을 0을 
	    넣어도 무관하다.
*/



//---------------------------------------------------------------- 
//   2) 소켓 닫기
//---------------------------------------------------------------- 
/*
   소켓을 이용한 통신이 끝나면 관련된 리소스 반환해야 한다. 
   int closesocket( SOCKET s );
*/





/*
 [ 정 리 ]

1. 대부분의 소켓 함수는 오류가 발생할 경우 WSAGetLastError() 함수를 
   이용하여 구체적인 오류 코드를 얻을 수 있다.

2. FormatMessage() 함수를 이용하면 오류 코드에 해당하는 오류 메시지를 
   얻을 수 있다. 
   
3. WSAStartup() 함수는 프로그램에서 사용할 윈속 버전을 요청함으로써 윈속 
   라이브러리(WS2_32.DLL)을 초기화하는 역할을 한다.

4. WSACleanup() 함수는 윈속 사용을 중지함을 운영체제에 알리고 관련 
   리소스를 반환하는 역할을 한다.

5. WSAStartup() 함수를 여러 번 호출할 수 있으며, 이 같은 경우 횟수반큼
   WSACleanup() 함수를 호출해야 한다.

6. socket() 함수는 사용자가 요청한 프로토콜을 이용하여 통신을 할 수 
   있도록 내부적으로 리소스를 할당하고, 이를 접근할 수 있는 일종의 
   핸들값을 리턴한다.
   이 같을 소켓 디스크립터(socket descriptor)라 부르며, 각종 소켓 함수를 
   호출할때 인자로 전달하여 사용한다.

7. socket()함수에 전달하는 인자는 주소 체계, 소켓 타입, 프로토콜이다.

8. closesocket() 함수는 해당 소켓을 닫고 관련 리소스를 반환하는 
   역할을 한다.


