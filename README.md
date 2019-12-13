# tArass
## Описание
Утилита для конвертации файла трассировки Afdpro в таблицу Excel
![tArass showdown](/assets/taras.gif "tArass showdown")
## Как использовать
Для начала вам потребуется файл трассировки Afdpro, который можно получить следующим образом:
1. Запустите ваш исполняемый файл в Afdpro
2. Находясь в отладчике Afdpro введите следующую команду `TR ON CLR`
3. Выполните нужное вам количество шагов
4. Введите команду `PT {start, lenght, {filename}}`, где `start` позиция кода с которой вы хотите начать трассировку(как правило 0), `length` длина вашего кода(как правило количество строк), `filename` путь к файлу, в который вы хотите сохранить полученные данные. Например `PT 0, 32, TRASS.TXT`

Полученый файл и есть файл трассировки. Далее вам нужно просто его указать как первый аргумент tArass. 
## Установка
### Windows
[Баг](https://github.com/jmcnamara/libxlsxwriter/issues/255) решён <3 \
Скачать бинарник можно [здесь](https://drive.google.com/file/d/16tQguszhfROxBM800INEaX_k48RkHxgF/view?usp=sharing).
### GNU/Linux
Для того чтобы использовать tArass на системах GNU/Linux вам понадомиться собрать исполняемый файл из исходного кода.
1. Установите библиотеку libxlsxwriter на основе этого [гайда](https://libxlsxwriter.github.io/getting_started.html#gsg_quick_start)
2. С помощью `gcc` скомпилируйте исходный код: `cc tarass.c -o tarass -lxlsxwriter`

Или же скачать готовый бинарный файл [отсюда](https://drive.google.com/open?id=1hCn9LhWEFUkKGM7zfs0Zsrv3trkyr9Yk)
### MacOS
Скоро...
## Планы
1. Makefile
2. Версия для MacOS
3. Парсинг файла листинга и создание соответствующей таблицы.
### Зависимости
1. [libxlsxwriter](https://github.com/jmcnamara/libxlsxwriter)
2. [zlib](https://github.com/madler/zlib)
