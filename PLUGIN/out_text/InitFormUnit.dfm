object InitForm: TInitForm
  Left = 407
  Top = 142
  BorderStyle = bsDialog
  ClientHeight = 32
  ClientWidth = 268
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
  object Button1: TButton
    Left = 80
    Top = 8
    Width = 105
    Height = 17
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
end
