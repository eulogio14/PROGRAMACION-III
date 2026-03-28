#!/usr/bin/env bash

project_name='prog3_unit1_fundamentos_v2026_01'
source_code='
  drone_system.h drone_system.cpp
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}