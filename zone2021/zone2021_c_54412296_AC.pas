/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54412296
 * Submitted at: 2024-06-09 23:47:53
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: AC
 * Execution Time: 3 ms
 */

program ThresholdSearch;

uses
  SysUtils, Math;

const
  ABILITY = 5;

type
  TIntArray = array of Integer;
  TMatrix = array of TIntArray;

var
  n, i, j, left, right, mid: Integer;
  p: TMatrix;

function ReadMatrix(rows, cols: Integer): TMatrix;
var
  i, j: Integer;
begin
  SetLength(Result, rows, cols);
  for i := 0 to rows - 1 do
    for j := 0 to cols - 1 do
      Read(Result[i][j]);
end;

function Check(x: Integer; p: TMatrix; n: Integer): Boolean;
var
  i, j, k, bit, v1, v2, v3: Integer;
  s: array of Integer;
  len: Integer;
  found: Boolean;
begin
  SetLength(s, 0);
  for i := 0 to n - 1 do
  begin
    bit := 0;
    for j := 0 to ABILITY - 1 do
    begin
      if p[i][j] >= x then
        bit := bit or (1 shl j);
    end;
    found := False;
    for k := 0 to High(s) do
      if s[k] = bit then
      begin
        found := True;
        Break;
      end;
    if not found then
    begin
      SetLength(s, Length(s) + 1);
      s[High(s)] := bit;
    end;
  end;

  len := Length(s);
  for i := 0 to len - 1 do
    for j := i to len - 1 do
      for k := j to len - 1 do
        if (s[i] or s[j] or s[k]) = (1 shl ABILITY) - 1 then
          Exit(True);

  Exit(False);
end;

begin
  ReadLn(n);
  p := ReadMatrix(n, ABILITY);

  left := 0;
  right := 1000000005;
  while right - left > 1 do
  begin
    mid := (right + left) div 2;
    if Check(mid, p, n) then
      left := mid
    else
      right := mid;
  end;

  WriteLn(left);
end.
