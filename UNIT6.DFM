object Form6: TForm6
  Left = 192
  Top = 103
  BorderStyle = bsNone
  Caption = 'Form6'
  ClientHeight = 335
  ClientWidth = 468
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = FormClick
  OnPaint = Timer1Timer
  PixelsPerInch = 96
  TextHeight = 13
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 40
    Top = 16
  end
end
