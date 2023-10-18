#!/bin/bash
#Reconstruct the luts
for i in {337,338,339,340,341,342,343,351,368,370,372,375,355,376,377,378,387,380,383,384,385,395,396,397,400,405,406,409,410,411,412,418,419,420,421,422,423,424,425,426,427,428,429,431,432,433,435};
do
    echo $i;
    $exe_grate -L $i
    echo "Finish $i"
done;

cp $data/LUT/CGEM_cosmic_look_up_table_337.root ~/lut_for_china/CGEM_cosmic_look_up_table_10.root;
cp $data/LUT/CGEM_cosmic_look_up_table_338.root ~/lut_for_china/CGEM_cosmic_look_up_table_11.root;
cp $data/LUT/CGEM_cosmic_look_up_table_339.root ~/lut_for_china/CGEM_cosmic_look_up_table_12.root;
cp $data/LUT/CGEM_cosmic_look_up_table_340.root ~/lut_for_china/CGEM_cosmic_look_up_table_13.root;
cp $data/LUT/CGEM_cosmic_look_up_table_341.root ~/lut_for_china/CGEM_cosmic_look_up_table_14.root;
cp $data/LUT/CGEM_cosmic_look_up_table_342.root ~/lut_for_china/CGEM_cosmic_look_up_table_15.root;
cp $data/LUT/CGEM_cosmic_look_up_table_343.root ~/lut_for_china/CGEM_cosmic_look_up_table_16.root;
cp $data/LUT/CGEM_cosmic_look_up_table_351.root ~/lut_for_china/CGEM_cosmic_look_up_table_17.root;
cp $data/LUT/CGEM_cosmic_look_up_table_368.root ~/lut_for_china/CGEM_cosmic_look_up_table_18.root;
cp $data/LUT/CGEM_cosmic_look_up_table_370.root ~/lut_for_china/CGEM_cosmic_look_up_table_19.root;
cp $data/LUT/CGEM_cosmic_look_up_table_372.root ~/lut_for_china/CGEM_cosmic_look_up_table_10.root;
cp $data/LUT/CGEM_cosmic_look_up_table_375.root ~/lut_for_china/CGEM_cosmic_look_up_table_21.root;
cp $data/LUT/CGEM_cosmic_look_up_table_355.root ~/lut_for_china/CGEM_cosmic_look_up_table_22.root;
cp $data/LUT/CGEM_cosmic_look_up_table_376.root ~/lut_for_china/CGEM_cosmic_look_up_table_23.root;
cp $data/LUT/CGEM_cosmic_look_up_table_377.root ~/lut_for_china/CGEM_cosmic_look_up_table_24.root;
cp $data/LUT/CGEM_cosmic_look_up_table_378.root ~/lut_for_china/CGEM_cosmic_look_up_table_25.root;
cp $data/LUT/CGEM_cosmic_look_up_table_387.root ~/lut_for_china/CGEM_cosmic_look_up_table_26.root;
cp $data/LUT/CGEM_cosmic_look_up_table_380.root ~/lut_for_china/CGEM_cosmic_look_up_table_27.root;
cp $data/LUT/CGEM_cosmic_look_up_table_383.root ~/lut_for_china/CGEM_cosmic_look_up_table_28.root;
cp $data/LUT/CGEM_cosmic_look_up_table_384.root ~/lut_for_china/CGEM_cosmic_look_up_table_29.root;
cp $data/LUT/CGEM_cosmic_look_up_table_385.root ~/lut_for_china/CGEM_cosmic_look_up_table_30.root;
cp $data/LUT/CGEM_cosmic_look_up_table_395.root ~/lut_for_china/CGEM_cosmic_look_up_table_31.root;
cp $data/LUT/CGEM_cosmic_look_up_table_396.root ~/lut_for_china/CGEM_cosmic_look_up_table_32.root;
cp $data/LUT/CGEM_cosmic_look_up_table_397.root ~/lut_for_china/CGEM_cosmic_look_up_table_33.root;
cp $data/LUT/CGEM_cosmic_look_up_table_400.root ~/lut_for_china/CGEM_cosmic_look_up_table_34.root;
cp $data/LUT/CGEM_cosmic_look_up_table_405.root ~/lut_for_china/CGEM_cosmic_look_up_table_35.root;
cp $data/LUT/CGEM_cosmic_look_up_table_406.root ~/lut_for_china/CGEM_cosmic_look_up_table_36.root;
cp $data/LUT/CGEM_cosmic_look_up_table_409.root ~/lut_for_china/CGEM_cosmic_look_up_table_37.root;
cp $data/LUT/CGEM_cosmic_look_up_table_410.root ~/lut_for_china/CGEM_cosmic_look_up_table_38.root;
cp $data/LUT/CGEM_cosmic_look_up_table_411.root ~/lut_for_china/CGEM_cosmic_look_up_table_39.root;
cp $data/LUT/CGEM_cosmic_look_up_table_412.root ~/lut_for_china/CGEM_cosmic_look_up_table_40.root;
cp $data/LUT/CGEM_cosmic_look_up_table_418.root ~/lut_for_china/CGEM_cosmic_look_up_table_41.root;
cp $data/LUT/CGEM_cosmic_look_up_table_419.root ~/lut_for_china/CGEM_cosmic_look_up_table_42.root;
cp $data/LUT/CGEM_cosmic_look_up_table_420.root ~/lut_for_china/CGEM_cosmic_look_up_table_43.root;
cp $data/LUT/CGEM_cosmic_look_up_table_421.root ~/lut_for_china/CGEM_cosmic_look_up_table_44.root;
cp $data/LUT/CGEM_cosmic_look_up_table_422.root ~/lut_for_china/CGEM_cosmic_look_up_table_45.root;
cp $data/LUT/CGEM_cosmic_look_up_table_423.root ~/lut_for_china/CGEM_cosmic_look_up_table_46.root;
cp $data/LUT/CGEM_cosmic_look_up_table_424.root ~/lut_for_china/CGEM_cosmic_look_up_table_47.root;
cp $data/LUT/CGEM_cosmic_look_up_table_426.root ~/lut_for_china/CGEM_cosmic_look_up_table_48.root;
cp $data/LUT/CGEM_cosmic_look_up_table_428.root ~/lut_for_china/CGEM_cosmic_look_up_table_49.root;
cp $data/LUT/CGEM_cosmic_look_up_table_425.root ~/lut_for_china/CGEM_cosmic_look_up_table_50.root;
cp $data/LUT/CGEM_cosmic_look_up_table_427.root ~/lut_for_china/CGEM_cosmic_look_up_table_51.root;
cp $data/LUT/CGEM_cosmic_look_up_table_429.root ~/lut_for_china/CGEM_cosmic_look_up_table_52.root;
cp $data/LUT/CGEM_cosmic_look_up_table_431.root ~/lut_for_china/CGEM_cosmic_look_up_table_53.root;
cp $data/LUT/CGEM_cosmic_look_up_table_432.root ~/lut_for_china/CGEM_cosmic_look_up_table_54.root;
cp $data/LUT/CGEM_cosmic_look_up_table_433.root ~/lut_for_china/CGEM_cosmic_look_up_table_55.root;
cp $data/LUT/CGEM_cosmic_look_up_table_435.root ~/lut_for_china/CGEM_cosmic_look_up_table_56.root;



