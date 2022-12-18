mod c_api {
    use pkm_rs::{types, Pa8, Pkx};

    #[no_mangle]
    pub unsafe extern "C" fn free_pa8(ptr: *mut Pa8) {
        crate::utils::free!(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_encryption_constant(ptr: *mut Pa8) -> u32 {
        crate::utils::run_method!(ptr, encryption_constant)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_species_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, species, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_tid(ptr: *mut Pa8) -> u16 {
        crate::utils::run_method!(ptr, tid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_sid(ptr: *mut Pa8) -> u16 {
        crate::utils::run_method!(ptr, sid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_ability_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, ability, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_ability_number(ptr: *mut Pa8) -> u8 {
        crate::utils::run_method!(ptr, ability_number) as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_pid(ptr: *mut Pa8) -> u32 {
        crate::utils::run_method!(ptr, pid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_nature_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, nature, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_minted_nature_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, minted_nature, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_gender(ptr: *mut Pa8) -> u8 {
        let pkm = crate::utils::open_box!(ptr);

        let gender = if pkm.is_valid() {
            pkm.gender()
        } else {
            types::Gender::Unknown
        };

        gender as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_evs(ptr: *mut Pa8) -> types::Stats {
        crate::utils::run_method!(ptr, evs)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_ivs(ptr: *mut Pa8) -> types::Stats {
        crate::utils::run_method!(ptr, ivs)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move1_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move1, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move2_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move2, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move3_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move3, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move4_string(
        ptr: *mut Pa8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move4, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_language(ptr: *mut Pa8) -> u8 {
        crate::utils::run_method!(ptr, language) as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_is_shiny(ptr: *mut Pa8) -> bool {
        crate::utils::run_method!(ptr, is_shiny)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_is_egg(ptr: *mut Pa8) -> bool {
        crate::utils::run_method!(ptr, is_egg)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_current_friendship(ptr: *mut Pa8) -> u8 {
        crate::utils::run_method!(ptr, current_friendship)
    }
}
