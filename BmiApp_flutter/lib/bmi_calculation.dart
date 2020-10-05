import 'dart:math';

import 'package:flutter/material.dart';

class BmiCalculation {

  BmiCalculation({this.height,this.weight});

  final int height;
  final int weight;
  double _bmi;

  String calculationBMI (){
    _bmi = weight / pow(height/100, 2);
    return _bmi.toStringAsFixed(1);
  }

  String getResult(){
    if(_bmi>=25){
      return 'Overweight';
    }
    else if(_bmi>18.5){
      return 'Normal';
    }
    else{
      return 'Underweight';
    }
  }

  String getComment (){
    if(_bmi>=25){
      return 'You have higher than normal body weight. Try to exercise more and eat less';
    }
    else if(_bmi>18.5){
      return 'You have a normal body weight. Good job! and try to maintain it.';
    }
    else{
      return 'You have a lower than normal body weight. You can eat a bit more and take supplements.';
    }
  }
}