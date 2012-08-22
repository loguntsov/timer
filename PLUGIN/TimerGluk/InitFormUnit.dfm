object InitForm: TInitForm
  Left = 219
  Top = 144
  BorderStyle = bsDialog
  ClientHeight = 23
  ClientWidth = 304
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 256
    Top = 0
    Width = 23
    Height = 22
    Caption = '+'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'Arial Black'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 280
    Top = 0
    Width = 23
    Height = 22
    Caption = '-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'Arial Black'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object cbTaskList: TComboBox
    Left = 0
    Top = 0
    Width = 257
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    OnClick = cbTaskListClick
    OnKeyPress = cbTaskListKeyPress
    Items.Strings = (
      '!!! Время истекло !!!')
  end
end
