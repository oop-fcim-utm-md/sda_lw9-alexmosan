# SDA, лабораторная работа 9

## Задание ##
Pеализовать список структур, используя заданную структуру данных.

Для списка из элементов-структур, каждый из которых имеет вид:
<br><code>
struct node_t
{
    node_t * next_;
    data_t data_;
};
</code><br>
-- (с данными в форме:
<br><code>
struct data_t
{
  int id_;
  char name_ [50];
};
</code><br>) написать следующие функции.

1. **clear** - очищает список, при необходимости освобождая задействованные для него ресурсы.
2. **tail** - возвращает последний элемент списка.
3. **length** - возвращает текущую длину списка.
4. **push_front** - добавляет новый элемент в начало списка.
5. **push_back** - добавляет новый элемент в конец списка.
6. **pop_front** - удаляет элемент из начала списка.
7. **pop_back** - удаляет элемент из конца списка.
8. **insert** - вставляет элемент в произвольное место в списке.
9. **remove** - удаляет элемент из списка относительно искомого значения строки (удаляется первый встречающийся элемент списка, строковое значение которого совпадает со вторым аргументом).

Файлы _header.h_ и _main.cpp_ оставлять без изменений.

## С чего начать
1. Скачайте последнюю версию git по ссылке: https://git-scm.com/downloads
2. Зарегистрируйтесь на github: https://github.com/
3. Создайте папку на компьютере для всех лабораторных, в которой необходимо инициализировать git одним из доступных способов (Git GUI, Git Bash, VSCode).

## Как работать с git
Используя этот репозиторий как пример:
1. Скопируйте код на свой компьютер с помощью команды*<br><br>
**git clone https://github.com/oop-fcim-utm-md/sda_lw9-<ваше имя пользователя>.git**<br><br>
*ссылка на репозиторий берется во вкладке* **<> Code** *на странице репозитория в github*<br>
*это автоматически инициализирует git с веткой* main *в папке с локальной версией репозитория*<br>
**требует авторизации (если через браузер не получается, необходимо сгенерировать Github [Personal Access Token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token))*
2. После того, как внесете значительные изменения в код, cохраните их с помощью команды<br><br>
**git commit -am "commit message"**<br><br>
*где* -am - *это дополнительные параметры, обозначающие выполнение команд add и message*<br>
*в кавычках следует писать сообщение о сути изменений в новой версии репозитория, которую вы создаете таким образом*
3. Для синхронизации файлов на github с локальными используйте команду*<br><br>
**git push origin main**<br><br>
*где* origin - *это указатель на удаленную ветку (точка назначения), а* main - *на локальную (источник)*<br>
*требует авторизации
