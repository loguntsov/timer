object InitForm: TInitForm
  Left = 219
  Top = 144
  BorderStyle = bsNone
  ClientHeight = 22
  ClientWidth = 297
  Color = 4194368
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
    Width = 21
    Height = 21
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
    Left = 276
    Top = 0
    Width = 21
    Height = 21
    Caption = '-'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'Arial Black'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 9
    Height = 22
    Align = alLeft
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object cbTaskList: TComboBox
    Left = 8
    Top = 0
    Width = 249
    Height = 21
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 0
    OnClick = cbTaskListClick
    OnKeyPress = cbTaskListKeyPress
  end
end
