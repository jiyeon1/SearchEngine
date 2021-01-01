# search-engine
2-1 data structure

아스키 코드로 표현되는 텍스트 파일 9개 (  document1.txt"~"document9.txt  )  

1.	색인과정   
문서를 읽어 각 단어들이 어느 문서에 몇 번이나 나타나는지에 대한 정보를 자료구조를 이용하여 저장한다.  

2.	검색과정  
사용자가 찾고자 하는 단어를 입력하면 미리 저장해 놓은 자료구조를 활용해 단어가 출현하는 문서 찾기  
문서명 / 단어 출현 빈도 / 그 단어가 출현한 문서 부분 (전후 4 단어씩) 출력  


>	대문자와 소문자는 같은 것으로 취급. 검색단어는 알파벳만. inform을 검색하면 information은 검색하지 않는다.   
>	문서파일은 영문자 (a~z, A~Z), 개행문자 ('\n', '\t', ' ', …) 및 문장부호 (“, ‘, ,, ., ?, …)들로 이루어져 있고, 단어와 단어 사이는 ‘ ’ (공백문자)로 구분된다.  
>	색인 과정이 종료된 후에는 총 문서 수, 색인된 총 단어 수, 색인이 완료될 때까지 수행한 스트링 비교연산 횟수를 출력한다. 이후 검색이 수행될 때마다 검색 결과와 함께 검색이 완료될 때까지 수행한 스트링 비교연산 회수를 출력한다.   
>	검색단어가 가장 많이 포함된 파일의 이름이 먼저 나오도록.  
>	가급적 비교연산 횟수가 작아지도록 해야함. (효율성)   
