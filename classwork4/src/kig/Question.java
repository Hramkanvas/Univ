package kig;

import java.util.List;

public class Question {
    /*тестирующая программа, вопросы, ответы, статистика
    вход - файл с вопросами
    текст вопроса ; количество возможных варианта ответа ; да; нет; возможно; номер правильного ответа;
    выход : на сколько вопросов человек ответил правильно в процентах
     */
    private String StringQ;
    private List<String> answers;
    private byte quantityOfVariants;
    private byte rightAnswer;
    public Question(String question, int quantityOfVariants, List<String> answers, int rightAnswer){
        this.StringQ = question;
        this.quantityOfVariants = (byte)quantityOfVariants;
        this.answers = answers;
        this.rightAnswer = (byte)rightAnswer;
    }
    //конструктор по умолчанию должен быть
    public byte getRightAnswer(){
        return this.rightAnswer;
    }

}