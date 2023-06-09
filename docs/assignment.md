---
layout: default
title: Assignment
nav_order: 7
permalink: /assignment/
---

# ЛАБОРАТОРНАЯ РАБОТА № 5

Разработка консольного приложения с применением технологий управления
проектом и командой, контроля версий и сборки проекта. Для выполнения
лабораторной работы сформировать группы из 2-3 человек и сообщить сведения о
составе группы преподавателю и лектору.

## Вариант 5. «Музыкальный салон»

Постоянно работающий музыкальный салон продает компакт-диски с записями
определенных исполнителей, поступающие от различных компаний-производителей.
Управление салона владеет информацией:

* о компакт-дисках: код компакта, дата изготовления, компания-производитель, цена одного компакта;
* об исполнителях музыкальных произведений: название музыкального произведения, автор, исполнитель, код компакта;
* о поступлении и продаже компактов: дата операции, код операции (поступление илипродажа), код компакта, количество экземпляров.

Покупатель может узнать информацию только о данных - смотрите ниже по пункту, помеченному * (звездочкой).

Необходимо выполнить:

1. Создать таблицы БД с учетом ограничений целостности данных.
2. Используя оператор Select, выдать следующую информацию:
  * по всем компактам – сведения о количестве проданных и оставшихся компактов
  одного вида по убыванию разницы;
  * по указанному компакту – сведения о количестве и стоимости компактов, проданных
  за указанный период;
  * по компакту, купленному максимальное количество раз, – выдать все сведения о нем
  и музыкальных произведениях(*);
  * по наиболее популярному исполнителю – сведения о количестве проданных
  компактов с его произведениями(*);
  * по каждому автору – сведения о количестве проданных компактов с его записями и
  сумме полученных денег.
3. Обеспечить с помощью операторов Insert, Update, Delete обновление информации в
указанных таблицах.
4. Создать функцию, который запрещает помещать информацию о продаже компактов в
таблицу, если суммарное количество проданных компактов превысит суммарное количество
поступивших.
5. Создать функцию, которая за указанный период определяет количество поступивших
и проданных компактов по каждому виду. В качестве параметра передать начальную дату
периода и конечную дату периода. Результаты занести в специальную таблицу.
6. Создать функцию, которая по заданному коду компакта выводит информацию о
результатах его продажи за указанный период(*).
