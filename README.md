# tArass
## Описание
Утилита для конвертации файла трассировки Afdpro в таблицу Excel
![tArass showdown](/assets/taras.gif "tArass showdown")
## Как использовать
Для начала вам потребуется файл трассировки Afdpro, который можно получить следующим образом:
<ol>
<li>Запустите ваш исполняемый файл в Afdpro</li>
<li>Находясь в отладчике Afdpro введите следующую команду `TR ON CLR`</li>
<li>Выполните нужное вам количество шагов</li>
<li>Введите команду `PT {start, lenght, {filename}}`, где `start` позиция кода с которой вы хотите начать трассировку(как правило 0), `length` длина вашего кода(как правило количество строк), `filename` путь к файлу, в который вы хотите сохранить полученные данные</li>
</ol>
Полученый файл и есть файл трассировки. Далее вам нужно просто его указать как первый аргумент tArass.
