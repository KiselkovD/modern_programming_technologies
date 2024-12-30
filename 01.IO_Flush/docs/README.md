## 01.IO_Flush

### задача:

- Откомпилировать и собрать программу, запустить, как есть.
  - ввод:
  - `PS C:\...\01.IO_Flush> .\build\main.exe`
  - вывод:
  - ```
    STDOUT
    STDERR
    PS C:\...\01.IO_Flush>
    ```
  ```

  ```
- Добвить символы '\n' в конец строк.
  - код:
  - ```
    puts("STDOUT\n");
    fflush(stdout);
    fputs("STDERR\n", stderr);
    fflush(stderr);
    ```
  ````
  - ввод:
  - `PS C:\...\01.IO_Flush> .\build\main.exe `
  - вывод:
  - ```
  STDOUT
  STDERR
  PS C:\...\01.IO_Flush>
  ````
- Убрать fflush
  - код:
  - ```
    puts("STDOUT\n");
    fputs("STDERR\n", stderr);
    ```
  - ввод:
  - `PS C:\...\01.IO_Flush> .\build\main.exe `
  - вывод:
  - ```
    STDOUT
    STDERR
    PS C:\...\01.IO_Flush>
    ```
  ```

  ```
- Перенаправить вывод (оба потока) в файл.

  - код:
  - ```
    puts("STDOUT\n");
    fputs("STDERR\n", stderr);
    ```

  ````
  - ввод:
  - `PS C:\...\01.IO_Flush> .\build\main.exe > .\tmp\log.txt 2>&1`
  - `PS C:\...\01.IO_Flush> type .\tmp\log.txt  `
  - вывод:
  - ```
    STDOUT
    .\build\main.exe : STDERR
    строка:1 знак:1
    + .\build\main.exe > .\tmp\log.txt 2>&1
    + ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    		+ CategoryInfo          : NotSpecified: (STDERR:String) [], RemoteException
    		+ FullyQualifiedErrorId : NativeCommandError

    PS C:\...\01.IO_Flush>
  ````

### доп исследование:

- код:
- ````
  	puts("[puts_STDOUT]");
  	fflush(stdout);
  	fputs("[fputs_STDOUT]", stdout);
  	fflush(stdout);
  	fputs("[fputs_STDERR]", stderr);
  	fflush(stderr);
  	printf("[printf_\\n_STDOUT]\n");
  	printf("[printf_STDOUT]");
  	```
  Windows 11 23H2:
  PS C:\...\01.IO_Flush > .\tests\run.bat
  ````
- ![alt text](<../res/image.png>)
- ```
  PS C:\...\01.IO_Flush> .\build\main
  [puts_STDOUT]
  [fputs_STDOUT][fputs_STDERR][printf_\n_STDOUT]
  [printf_STDOUT]
  PS C:\...\01.IO_Flush>
  ```
- ```
  PS C:\...\01.IO_Flush> type .\tmp\log.txt
  [puts_STDOUT]
  [fputs_STDOUT][fputs_STDERR][printf_\n_STDOUT]
  [printf_STDOUT]
  PS C:\...\01.IO_Flush> cmd
  ```
- ```
  Microsoft Windows [Version 10.0.22631.4460]
  (c) Корпорация Майкрософт (Microsoft Corporation). Все права защищены.

  C:\...\01.IO_Flush>type .\tmp\log.txt
  [puts_STDOUT]
  [fputs_STDOUT][fputs_STDERR][printf_\n_STDOUT]
  [printf_STDOUT]
  C:\...\01.IO_Flush>
  ```

вывод:

    в файле log.txt не было последнего отступа но power shell и cmd всеравно вывели его корректно, похоже power shell и cmd самостоятельно добавляют отступ
