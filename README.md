# OC_lab_4

«Синхронизация процессов при помощи событий, мьютексов и семафоров».

При реализации синхронизации процессов использовать функции ожидания сигнального состояния объекта только с
равным нулю или бесконечности интервалом ожидания. Каждый отдельный процесс открывать в отдельном
консольном окне. Использовать функцию WaitForMultipleObject для ожидания одного из группы событий.

ПЕРЕДАЧА СООБЩЕНИЙ : Отправить сообщение, например, А или В от одного процесса другому, в данном задании
означает : создаем события соответсвующие сообщениям А и В. Затем вводится одно из сообщений (А или В) с
консоли в одном процессе и устанавливается соответсвующее событие в сигнальное состояние. В другом процессе
ожидается одно из событии и выводится на консоль соответствующее сообщение.

АКТИВНЫЙ процесс- процесс, который может отправить сообщение, введённое с консоли и получить сообщение.

Написать программы для консольного процесса Administrator и консольных процессов Reader и Writer. Для
моделирования передачи сообщений ввести специальные события(c ручным сбросом для Reader), которые обозначают
сообщение “A” , сообщение “B”, и автоматическое событие - конец сеанса для процессов Reader и Writer.

Одновременно принимать и отправлять сообщения могут только ОДИН АКТИВНЫЙ процесс Writer(использовать
мьютекс), и ДВА АКТИВНЫХ процесса Reader(использовать семафор), передача остальных сообщений от
других процессов должна временно блокироваться (находиться в режиме ожидания).

Процесс Administrator:

 Инициализация объектов синхронизации;

 запрашивает у пользователя k-количество процессов Writer ( количество процессов Reader =2*k),
которые он должен запустить;

 запрашивает у пользователя кол-во отправленных и принятых сообщений для процессов Writer и Reader

 запускает заданное количество процессов Reader и Writer

 принимает от каждого процесса Reader и Writer сообщение о завершении сеанса и выводит его на
консоль в одной строке.

 завершает свою работу.

Процесс Writer:

 синхронизировать работу процессов Writer с помощью мьютекса

 после захвата мьютекса выводить сообщение : мьютекс захвачен

 передачу сообщений реализовать с помощью событий c ручным сбросом

 апрашивает с консоли сообщения, и передает их (по одному) процессам Reader;

 передает сообщение (c автоматическим сбросом ) о завершении сеанса процессу Administrator;

 завершает свою работу.

Процесс Reader:

 синхронизировать работу процессов Reader с помощью семафора;

 после захвата мьютекса выводить сообщение : семафор захвачен;

 передачу сообщений реализовать с помощью событий;

 принимает сообщения (c ручным сбросом) от процесса Writer;

 выводит на консоль сообщения;

 передает сообщение (c автоматическим сбросом ) о завершении сеанса процессу Administrator;
завершает свою работу.
