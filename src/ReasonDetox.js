export function by_id(id) {
    return by.id(id);
}

export function by_text(text) {
    return by.text(text);
}

export async function element_tap(by) {
    return await element(by).tap();
}

export async function detox_element_id_typeText(id, value) {
    // console.log('>>> detox_element_id_typeText: ' + id + " " + value);
    return await element(by.id(id)).typeText(value);
}

export async function detox_expect_text_toBeVisible(text) {
    // console.log('>>> detox_expect_visible: ' + text);
    return await expect(element(by.text(text))).toBeVisible();
}

export async function detox_expect_id_toHaveText(id, expected) {
    // console.log('>>> detox_expect_text: ' + id + '=' + expected);
    return await expect(element(by.id(id))).toHaveText(expected);
}
