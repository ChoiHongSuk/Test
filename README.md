Practice C Language Project

1. HTTP RFC표준 기반 파싱
> * HTTP 헤더를 RFC표준에 맞게 재가공
> > """ C
abcd
"""
 
2. 사용방법
> * 프로그램 실행 시 인자로 dumping한 http request 헤더 파일경로를 입력
> * 해당 경로 파일을 읽어 RFC표준에 맞게 정리된 새 파일을 생성

3. 소스코드
> * 주요 구조체
> 	> 1. struct request
>	> 2. struct node node
>	> 3. struct node list

* 주요 함수
  * file_read
    * 파일을 읽어드려 버퍼를 생성
  * file_write
    * 파싱한 결과물을 파일로 출력
  * buf_devide
    * 버퍼를 라인별로 쪼갬
  * req_extractor
     * 요청 헤더 파싱
  * head_extractor
    * 요청 헤더 파싱
