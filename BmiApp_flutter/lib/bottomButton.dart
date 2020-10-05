import 'package:flutter/material.dart';
import 'constants.dart';


class BottomButton extends StatelessWidget {

  BottomButton({@required this.buttonTitle,@required this.onTap});

  final Function onTap;
  final String buttonTitle;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onTap,
      child: Container(
        child: Center(
          child: Text(
            buttonTitle,
            style: kContainerTextStyle,
          ),
        ),
        padding: EdgeInsets.only(bottom: 20.0, top: 10.0),
        width: double.infinity,
        height: kBottomCardHeight,
        margin: EdgeInsets.only(top:10.0),
        decoration:BoxDecoration(
//              borderRadius: BorderRadius.circular(10),
          color: kBottomContainerColour,
        ),
      ),
    );
  }
}