
import 'package:flutter/material.dart';
import 'constants.dart';


class IconWidget extends StatelessWidget {
   IconWidget({this.iconType,this.iconText});
   final IconData iconType;
   final String iconText;

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Icon(
          iconType,
          size: 80.0,
        ),
        SizedBox(height: 15.0,),
        Text(
           iconText,
          style: kLabelTextStyle,
        ),
      ],
    );
  }
}